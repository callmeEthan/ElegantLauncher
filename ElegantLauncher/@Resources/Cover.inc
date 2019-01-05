[Game1] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "1"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 1"] 
  
[Game2] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "2"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 2"] 
  
[Game3] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "3"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 3"] 
  
[Game4] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "4"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 4"] 
  
[Game5] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "5"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 5"] 
  
[Game6] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "6"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 6"] 
  
[Game7] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "7"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 7"] 
  
[Game8] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "8"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 8"] 
  
[Game9] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "9"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 9"] 
  
[Game10] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "10"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 10"] 
  
[Game11] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "11"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 11"] 
  
[Game12] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "12"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 12"] 
  
[Game13] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "13"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 13"] 
  
[Game14] 
Meter=Image 
MeterStyle=GameIcon 
X=0 
Y=0 
MouseOverAction=[Play "#@#Sounds\Hover.wav"][!SetVariable Select "14"][!CommandMeasure "Script" "animation_update()"] 
LeftMouseUpAction=!Execute [!CommandMeasure InputExecute "Execute 14"] 
  
  
[Title1] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename1# 
  
[Title2] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename2# 
  
[Title3] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename3# 
  
[Title4] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename4# 
  
[Title5] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename5# 
  
[Title6] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename6# 
  
[Title7] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename7# 
  
[Title8] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename8# 
  
[Title9] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename9# 
  
[Title10] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename10# 
  
[Title11] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename11# 
  
[Title12] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename12# 
  
[Title13] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename13# 
  
[Title14] 
Meter=String 
MeterStyle=GameTitle 
Text=#Gamename14# 
  
[InputExecute] 
Measure=Plugin 
Plugin=ActionTimer 
DynamicVariables=1 
ActionList1=Select1|Deactivate 
ActionList2=Select2|Deactivate 
ActionList3=Select3|Deactivate 
ActionList4=Select4|Deactivate 
ActionList5=Select5|Deactivate 
ActionList6=Select6|Deactivate 
ActionList7=Select7|Deactivate 
ActionList8=Select8|Deactivate 
ActionList9=Select9|Deactivate 
ActionList10=Select10|Deactivate 
ActionList11=Select11|Deactivate 
ActionList12=Select12|Deactivate 
ActionList13=Select13|Deactivate 
ActionList14=Select14|Deactivate 
Select1=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir1#"] 
Select2=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir2#"] 
Select3=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir3#"] 
Select4=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir4#"] 
Select5=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir5#"] 
Select6=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir6#"] 
Select7=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir7#"] 
Select8=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir8#"] 
Select9=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir9#"] 
Select10=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir10#"] 
Select11=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir11#"] 
Select12=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir12#"] 
Select13=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir13#"] 
Select14=!Execute [Play "#@#Sounds\Launch.wav"]["#Gamedir14#"] 
Deactivate=[!CommandMeasure Exit "Execute 1" "ElegantLauncher"] 
