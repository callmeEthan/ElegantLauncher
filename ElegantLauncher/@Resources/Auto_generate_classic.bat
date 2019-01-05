echo off
cls

set count=%1
if %count% lss 1 (echo Invalid parameter) & (pause) & (goto END)
echo Input: %count%
set index=1
set entry=0
IF EXIST Cover.inc (del /q Cover.inc)
echo writing game panel...

:LOOP
:WRITEGAME
@echo [Game%index%] >>Cover.inc
@echo Meter=Image >>Cover.inc
@echo MeterStyle=GameIcon >>Cover.inc
@echo X=0 >>Cover.inc
@echo Y=0 >>Cover.inc
@echo MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "%index%"][!CommandMeasure "Script" "animation_update()"] >>Cover.inc
@echo LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute %index%"] >>Cover.inc
@echo.  >>Cover.inc
:CHECKGAME
if %index% geq  %count% goto LOOPTITLE
set/a index=%index%+1
set/a entry=%index%-1
goto WRITEGAME


:LOOPTITLE
@echo.  >>Cover.inc
set index=1
set entry=0
:WRITETITLE
@echo [Title%index%] >>Cover.inc
@echo Meter=String >>Cover.inc
@echo MeterStyle=GameTitle >>Cover.inc
@echo Text=#Gamename%index%# >>Cover.inc
@echo.  >>Cover.inc

:CHECKTITLE
if %index% geq  %count% goto INPUTEXECUTE
set/a index=%index%+1
set/a entry=%index%-1
goto WRITETITLE


:INPUTEXECUTE
echo writting panel action...
set index=1
@echo [InputExecute] >>Cover.inc
@echo Measure=Plugin >>Cover.inc
@echo Plugin=ActionTimer >>Cover.inc
@echo DynamicVariables=1 >>Cover.inc
:ADDACTION
@echo ActionList%index%=Select%index%^|Deactivate >>Cover.inc
set/a index=%index%+1
if %index% LEQ %count% goto ADDACTION
set index=1

:ADDCOMMAND
@echo Select%index%=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir%index%#"] >>Cover.inc
set/a index=%index%+1
if %index% LEQ %count% goto ADDCOMMAND
@echo Deactivate=[!CommandMeasure Exit "Execute 1" "ElegantLauncher"] >>Cover.inc
goto FINISH

@echo.  >>Cover.inc
@echo [TotalGameCheck] >>Cover.inc
@echo Measure=Calc >>Cover.inc
@echo Formula=TotalGameCheck+1 >>Cover.inc
@echo IfConditionMode=1 >>Cover.inc
@echo DynamicVariables=1 >>Cover.inc
@echo IfCondition=(TotalGameCheck^>#TotalGame#) >>Cover.inc
@echo IfTrueAction=[!HideMeter "Game[TotalGameCheck]"] >>Cover.inc
@echo IfCondition2=(TotalGameCheck^>#TotalGame#) ^|^| (#Title#=0) >>Cover.inc
@echo IfTrueAction2=[!HideMeter "GameTitle[TotalGameCheck]"] >>Cover.inc
@echo IfCondition3=(TotalGameCheck=%count%) >>Cover.inc
@echo IfTrueAction3=[!DisableMeasure #CURRENTSECTION#] >>Cover.inc

:FINISH

:END
echo Completed!
timeout 1 >nul