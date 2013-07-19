;NSIS Modern User Interface
;Basic Example Script
;Written by Joost Verburg

;--------------------------------
;Include Modern UI

!include "MUI2.nsh"

;--------------------------------
;General
;-------------------------------- ������Ϣ
!define PRODUCT_NAME "RegExTester"
!define PRODUCT_EXENAME "RegExTester"
!define PRODUCT_VER "1.0.2.1"

; ��װ��
  Name "${PRODUCT_NAME}"
;Name "IBM BluePage"
; ���ɵİ�װ�ļ���������·��Ϊ��ǰĿ¼������ʹ������
;  OutFile "${PRODUCT_NAME}.${PRODUCT_VER}.${__DATE__}.exe"
  OutFile "${PRODUCT_NAME}.${PRODUCT_VER}.${__DATE__}.exe"
;--------------------------------
SetCompressor lzma
CRCCheck on

;��װ�ļ��汾��Ϣ  
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

;����
;!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "SimpChinese"
;--------------------------------
;Reserve Files
  
  ;If you are using solid compression, files that are required before
  ;the actual installation should be stored first in the data block,
  ;because this will make your installer start faster.
  
!insertmacro MUI_RESERVEFILE_LANGDLL


; Ĭ�ϵİ�װ·����$PROGRAMFILES Ϊ�������� Program Files
InstallDir "$PROGRAMFILES\${PRODUCT_NAME}"
; ������ʾ��װ���
ShowInstDetails show
; ������ʾж������
ShowUninstDetails nevershow 

; ��װ�����д��ڱ�������ʾ�ı��⣬û������ʱ����ʾ Name ��
;Caption "����"

;InstallButtonText ��װ���߰�

; �����ļ�
;LicenseData "TestSrc/readme.txt"

; ��Ȩ/�̱���Ϣ��Ҳ���ǰ�װ�������½ǵ����֣�Ĭ���� Nullsoft XXX
BrandingText "${PRODUCT_NAME} ${__DATE__}"


; ������ʾ��װ���
ShowInstDetails show
; ������ʾж������
ShowUninstDetails nevershow 


  
;--------------------------------
;���֤�ļ�
;LicenseData License-Chinese.txt

;--------------------------------
;Installer Sections
;-------------------------------- ��װ�ļ��б�

Section "!��װ" 

  SetOutPath "$INSTDIR"
  
  ; �ڰ�װ·���´��� dir Ŀ¼
  ; CreateDirectory $INSTDIR\dir

  ; �� TestSrc\TestFile1.txt ����Ϊ temp.dat 
  ;File "/oname=$INSTDIR\dir\temp.dat" TestSrc\TestFile1.txt

  ; ��ǰĿ¼�µ������ļ�����ԭĿ¼�ṹ��������װ�ļ���
  ; /x ѡ���ų����� *.nsi �ļ���.svn Ŀ¼��ѡ������˳��ģ�
  ; /r ���� /x ��߻ᱨ��
  ;File /r /x *.nsi /x .svn  *.*

  ; ���Թ۲췽�㣬���������ļ�
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
;Section "���뿪ʼ�˵�"
;  CreateDirectory "$SMPROGRAMS\${PRODUCT_NAME}"
;  CreateShortCut "$SMPROGRAMS\${PRODUCT_NAME}\${PRODUCT_NAME}.lnk" "$INSTDIR\${PRODUCT_EXENAME}.exe" 
;  CreateShortCut "$SMPROGRAMS\${PRODUCT_NAME}\ж��.lnk" "$INSTDIR\Uninstall.exe" 
;SectionEnd

Section "�����ݷ�ʽ"
  CreateShortCut "$DESKTOP\${PRODUCT_NAME}.lnk" "$INSTDIR\${PRODUCT_EXENAME}.exe" 
SectionEnd
Section "��������"
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

;��ʾ����ѡ��
;Function .onInit

  ;!insertmacro MUI_LANGDLL_DISPLAY

;FunctionEnd


