@echo off

set thisPath=%cd%
set unreal="C:\Program Files\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor.exe"
set projExt=*.uproject

pushd %thisPath%
for %%a in (%projExt%) do set projName=%%a
popd

%unreal% "%thisPath%\%projName%" -game -windowed -resx=1280 -resy=720