;NSIS Modern User Interface
;Basic Example Script
;Written by Joost Verburg

;--------------------------------
;Include Modern UI

!include "MUI2.nsh"

;--------------------------------
;General
;-------------------------------- 基本信息
!define PRODUCT_NAME "RegExTester"
!define PRODUCT_EXENAME "RegExTester"
!define PRODUCT_VER "1.0.2.1"

; 安装名
  Name "${PRODUCT_NAME}"
;Name "IBM BluePage"
; 生成的安装文件名：不带路径为当前目录，可以使用中文
;  OutFile "${PRODUCT_NAME}.${PRODUCT_VER}.${__DATE__}.exe"
  OutFile "${PRODUCT_NAME}.${PRODUCT_VER}.${__DATE__}.exe"
;--------------------------------
SetCompressor lzma
CRCCheck on

;安装文件版本信息  
  ;VIProductVersion ${PRODUCT_VER}
  ;VIAddVersionKey "ProductName" ${PRODUCT_NAME}
  ;VIAddVersionKey "Comments" "A test comment"
  ;VIAddVersionKey "CompanyName" "Fake company"
  ;VIAddVersionKey "LegalTrademarks" "Test Application is a trademark of Fake company"
  ;VIAddVersionKey "LegalCopyright" "?Fake company"
  ;VIAddVersionKey "FileDescription" "Test Application"
  ;VIAddVersionKey "FileVersion" ${PRODUCT_VER}

;Interface Configuration
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\orange-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\orange-uninstall.ico"
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Header\orange.bmp"
!define MUI_HEADERIMAGE_UNBITMAP "${NSISDIR}\Contrib\Graphics\Header\orange-uninstall.bmp"
!define MUI_WELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange-uninstall.bmp"

!define MUI_ABORTWARNING


;--------------------------------
;Pages
!insertmacro MUI_PAGE_WELCOME
;!insertmacro MUI_PAGE_LICENSE "License-Chinese.txt"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!define MUI_FINISHPAGE_RUN "$INSTDIR\${PRODUCT_EXENAME}.exe" 
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

;语言
;!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "SimpChinese"
;--------------------------------
;Reserve Files
  
  ;If you are using solid compression, files that are required before
  ;the actual installation should be stored first in the data block,
  ;because this will make your installer start faster.
  
!insertmacro MUI_RESERVEFILE_LANGDLL


; 默认的安装路径，$PROGRAMFILES 为环境变量 Program Files
InstallDir "$PROGRAMFILES\${PRODUCT_NAME}"
; 控制显示安装情况
ShowInstDetails show
; 控制显示卸载详情
ShowUninstDetails nevershow 

; 安装过程中窗口标题栏显示的标题，没有设置时会显示 Name 等
;Caption "标题"

;InstallButtonText 安装工具包

; 条款文件
;LicenseData "TestSrc/readme.txt"

; 版权/商标信息，也就是安装界面左下角的文字，默认是 Nullsoft XXX
BrandingText "${PRODUCT_NAME} ${__DATE__}"


; 控制显示安装情况
ShowInstDetails show
; 控制显示卸载详情
ShowUninstDetails nevershow 


  
;--------------------------------
;许可证文件
;LicenseData License-Chinese.txt

;--------------------------------
;Installer Sections
;-------------------------------- 安装文件列表

Section "!安装" 

  SetOutPath "$INSTDIR"
  
  ; 在安装路径下创建 dir 目录
  ; CreateDirectory $INSTDIR\dir

  ; 把 TestSrc\TestFile1.txt 拷贝为 temp.dat 
  ;File "/oname=$INSTDIR\dir\temp.dat" TestSrc\TestFile1.txt

  ; 当前目录下的所有文件按照原目录结构拷贝到安装文件夹
  ; /x 选项排除以下 *.nsi 文件、.svn 目录，选项是与顺序的，
  ; /r 放在 /x 后边会报错
  ;File /r /x *.nsi /x .svn  *.*

  ; 测试观察方便，拷贝所有文件
  File ..\bin\RegExTester.exe

  ;VC9 DLL
  CreateDirectory "$INSTDIR\Microsoft.VC90.CRT"
  SetOutPath "$INSTDIR\Microsoft.VC90.CRT"
  File "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\msvcm90.dll"
  File "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\msvcp90.dll"
  File "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\msvcr90.dll"
  File "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\Microsoft.VC90.CRT.manifest"
  
  ;Store installation folder
  ;WriteRegStr HKCU "Software\Modern UI Test" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd
; Optional section (can be disabled by the user)
;Section "加入开始菜单"
;  CreateDirectory "$SMPROGRAMS\${PRODUCT_NAME}"
;  CreateShortCut "$SMPROGRAMS\${PRODUCT_NAME}\${PRODUCT_NAME}.lnk" "$INSTDIR\${PRODUCT_EXENAME}.exe" 
;  CreateShortCut "$SMPROGRAMS\${PRODUCT_NAME}\卸载.lnk" "$INSTDIR\Uninstall.exe" 
;SectionEnd

Section "桌面快捷方式"
  CreateShortCut "$DESKTOP\${PRODUCT_NAME}.lnk" "$INSTDIR\${PRODUCT_EXENAME}.exe" 
SectionEnd
Section "快速启动"
  CreateShortCut "$QUICKLAUNCH\${PRODUCT_NAME}.lnk" "$INSTDIR\${PRODUCT_EXENAME}.exe" 
SectionEnd

;--------------------------------
;Uninstaller Section

Section "Uninstall"

  RMDir /r "$INSTDIR"
  Delete "$INSTDIR\Uninstall.exe"
  ;DeleteRegKey /ifempty HKCU "Software\Modern UI Test"
  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\${PRODUCT_NAME}\*.*"
  ;Delete "$SMSTARTUP\${PRODUCT_NAME}.lnk"
  Delete "$DESKTOP\${PRODUCT_NAME}.lnk"
  Delete "$QUICKLAUNCH\${PRODUCT_NAME}.lnk"
  ; Remove directories used
  RMDir "$SMPROGRAMS\${PRODUCT_NAME}"
  RMDir "$INSTDIR"
SectionEnd

;显示语言选择
;Function .onInit

  ;!insertmacro MUI_LANGDLL_DISPLAY

;FunctionEnd


