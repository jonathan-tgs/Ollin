Write-Host "Ejecutando re2c..." -ForegroundColor Cyan
re2c pre_src/pre_Ollin.cpp -o src/Ollin.cpp
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error en re2c" -ForegroundColor Red
    exit $LASTEXITCODE
}
Write-Host ""

Write-Host "Ejecutando ninja..." -ForegroundColor Cyan
ninja -C build
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error en ninja" -ForegroundColor Red
    exit $LASTEXITCODE
}
Write-Host ""

Write-Host "Ejecutando lexer.exe..." -ForegroundColor Cyan
.\build\lexer.exe
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error al ejecutar lexer.exe" -ForegroundColor Red
    exit $LASTEXITCODE
}
Write-Host ""

Write-Host "Script completado exitosamente" -ForegroundColor Green