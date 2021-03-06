[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
;Type=Blur
Type=Acrylic
Border=None

[Background]
Meter=Image
SolidColor=0,0,0,80
W=#SkinWidth#
H=#SkinHeight#
PreserveAspectRatio=2 

[MeterBorder]
Meter=Shape
Shape=Rectangle (#SkinWidth#*0.3) , 0 , (#SkinWidth#*0.7), #SkinHeight#, 0 | Fill Color 0,0,0,230

[CloseButton]
Meter=Image
ImageName=close.png
X=(#SkinWidth#-70)
Y=0
W=50
H=30
Padding=10,10,10,10
ImageTint=255,255,255,150
SolidColor=0,0,0,1
LeftMouseUpAction=!Execute [!DeactivateConfig "ElegantLauncher\Wizard"][Play "#@#Sounds\Click.wav"]
MouseOverAction=[!SetOption "#CURRENTSECTION#" "SolidColor" "255,50,50,255"][!SetOption "#CURRENTSECTION#" "ImageTint" "255,255,255,255"][Play "#@#Sounds\Dock.wav"]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" "SolidColor" "0,0,0,1"][!SetOption "#CURRENTSECTION#" "ImageTint" "255,255,255,150"]


[MeterTitle]
Meter=String
StringAlign=LEFTTOP
X=10
Y=10
FontSize=15
FontColor=255,255,255,255
FontWeight=100
FontFace=Source Sans Pro ExtraLight
AntiAlias=1
Text="Setting"

[DescStyle]
Meter=String
StringAlign=LEFTTOP
X=(#SkinWidth#*0.3)+30
W=(#SkinWidth#*0.7)-60
H=(#SkinHeight#*0.3)
ClipString=1
FontSize=20
FontColor=255,255,255,100
FontFace=Source Sans Pro ExtraLight
AntiAlias=1
[TitleStyle]
StringAlign=LEFTTOP
FontSize=20
FontColor=#Color#,200
FontFace=Source Sans Pro ExtraLight
AntiAlias=1
DynamicVariables=1

[Others2]
Meter=String
MeterStyle=MeterDir
X=10
Y=(#SkinHeight#*0.6)
W=(#SkinWidth#*0.3)-25
H=50
ClipString=1
Text="Change the number of panel to show"
FontSize=12
FontColor=255,255,255,255
MouseOverAction=[!SetOption "#CURRENTSECTION#" "FontColor" "#Color#,255"]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" "FontColor" "255,255,255,255"]
LeftMouseUpAction=!Execute [!ActivateConfig "ElegantLauncher\Wizard" "Panel.ini"][Play "#@#Sounds\Click.wav"]

[Others3]
Meter=String
MeterStyle=MeterDir
X=10
Y=80r
W=(#SkinWidth#*0.3)-25
H=50
ClipString=1
Text="Edit skin size in settings.inc"
FontSize=12
FontColor=255,255,255,255
MouseOverAction=[!SetOption "#CURRENTSECTION#" "FontColor" "#Color#,255"]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" "FontColor" "255,255,255,255"]
LeftMouseUpAction=!Execute ["#@#Settings.inc"][!DeactivateConfig "ElegantLauncher\Wizard"][Play "#@#Sounds\Click.wav"]


[MeterDir]
Meter=String
StringAlign=LEFTTOP
X=10
Y=32r
FontSize=20
FontColor=255,255,255,180
FontFace=Source Sans Pro ExtraLight
AntiAlias=1
[Dir1Active]
Meter=String
MeterStyle=MeterDir
Y=80
Text="General"
FontColor=255,255,255,255
FontWeight=800
Hidden=(#active#=1 ? 0 : 1)
[Dir1]
Meter=String
MeterStyle=MeterDir
Y=80
Text="General"
MouseOverAction=[!SetOption "#CURRENTSECTION#" "FontColor" "255,255,255,255"][Play "#@#Sounds\Dock.wav"][!ShowMeter MeterHighlight1]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" "FontColor" "255,255,255,180"][!HideMeter MeterHighlight1]
LeftMouseUpAction=!Execute [!ActivateConfig "ElegantLauncher\Wizard" "Configuration.ini"][Play "#@#Sounds\Click.wav"]
Hidden=(#active#=1 ? 1 : 0)

[Dir2Active]
Meter=String
MeterStyle=MeterDir
Text="List layout"
FontColor=255,255,255,255
FontWeight=800
Hidden=(#active#=2 ? 0 : 1)
[Dir2]
Y=0r
Meter=String
MeterStyle=MeterDir
Text="List layout"
MouseOverAction=[!SetOption "#CURRENTSECTION#" "FontColor" "255,255,255,255"][Play "#@#Sounds\Dock.wav"][!ShowMeter MeterHighlight2]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" "FontColor" "255,255,255,180"][!HideMeter MeterHighlight2]
LeftMouseUpAction=!Execute [!ActivateConfig "ElegantLauncher\Wizard" "Layout.ini"][Play "#@#Sounds\Click.wav"]
Hidden=(#active#=2 ? 1 : 0)


[MeterHighlight]
Meter=Shape
Shape=Rectangle 0 , (80+(#active#-1)*32) , 10, 32, 0 | Fill Color #Color#,255 |  Stroke Color #Color#,1
[MeterHighlight1]
Meter=Shape
Shape=Rectangle 0 , 80 , (#SkinWidth#*0.3), 32, 0 | Fill Color 255,255,255,100 |  Stroke Color #Color#,1
Hidden=1
[MeterHighlight2]
Meter=Shape
Shape=Rectangle 0 , (80+32) , (#SkinWidth#*0.3), 32, 0 | Fill Color 255,255,255,100 |  Stroke Color #Color#,1
Hidden=1
[MeterHighlight3]
Meter=Shape
Shape=Rectangle 0 , (80+32*2) , (#SkinWidth#*0.3), 32, 0 | Fill Color 255,255,255,100 |  Stroke Color #Color#,1
Hidden=1