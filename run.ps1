Write-Host "re2c..." -ForegroundColor Cyan
re2c pre_src/lexer.cpp -o src/lexer/lexer.cpp
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error en re2c" -ForegroundColor Red
    exit $LASTEXITCODE
}
Write-Host ""

Write-Host "ninja..." -ForegroundColor Cyan
ninja -C build
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error en ninja" -ForegroundColor Red
    exit $LASTEXITCODE
}
Write-Host ""

Write-Host "lexer.exe..." -ForegroundColor Cyan
.\build\lexer.exe
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error al ejecutar lexer.exe" -ForegroundColor Red
    exit $LASTEXITCODE
}
Write-Host ""

Write-Host "Boom" -ForegroundColor Green