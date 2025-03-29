param (
    [Parameter(Mandatory = $false)][string]$task
)

$workspaceFolderBasename = (Get-Item -Path ".").Name
$elfFile = "$workspaceFolderBasename.elf"
$hexFile = "$workspaceFolderBasename.hex"
$binFile = "$workspaceFolderBasename.bin"

function CMakeConfigure {
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -GNinja -Bbuild
}

function CMakeBuild {
    $flag = $true
    if (-not (Test-Path -Path "build/$elfFile")) {
        CMakeConfigure
        if (!$?) {
            $flag = $false
            Write-Error "CMakeConfigure failed!"
        }
    }
    
    if ($flag) {
        cmake --build build --target all
        if ($?) {
            arm-none-eabi-objcopy -Oihex "build/$elfFile" "build/$hexFile"
            if ($?) {
                arm-none-eabi-objcopy -Obinary "build/$elfFile" "build/$binFile"
            }
        }
    }
}

function Flash {
    $flag = $true
    if (-not (Test-Path -Path "build/$elfFile")) {
        CMakeBuild
        if (!$?) {
            $flag = $false
        }
    }
    if ($flag) {
        openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program ./build/$hexFile verify reset exit"
    }
}

function DeleteBuild {
    if (Test-Path -Path 'build') {
        Remove-Item -Path 'build' -Recurse -Force
        if ($?) {
            Write-Host 'Delete build directory success'
        }
    } else {
        Write-Host 'build 目录不存在，无需删除。'
    }
}

switch ($task) {
    "CMakeConfigure" { CMakeConfigure }
    "CMakeBuild" { CMakeBuild }
    "Flash" { Flash }
    "DeleteBuild" { DeleteBuild }
    default {
        Write-Host "Invalid task. Available tasks: CMakeConfigure, CMakeBuild, Flash, DeleteBuild"
    }
}