@echo off
setlocal EnableDelayedExpansion
@for %%n in (%0) do set fold=%%~dpn
mode con cols=80 lines=15

:Definition environement
set /A compt=0
set in=%fold%in.bat
set out=%fold%out.bat
set fichier=temp.txt
set resultatScan=resultat_Scan_reseau.txt
set titre=Detection de l'ip publique
set titre1=Reseau local

set /A ligne=0
title -==*==-  %titre% -==*==-
echo %titre% 
(
echo Dim objHttp,sText
echo     Set objHttp = CreateObject("Msxml2.ServerXMLHTTP"^)
echo     objHttp.Open "GET", "https://whatismyipaddress.com/", False
echo.
echo     objHttp.Send
echo     sText = objHttp.ResponseText
echo     path = sText
echo     posA = InStrRev(path, "document.write("^)+16
echo     posB = InStrRev(path, ");"^)-1
echo     WScript.Echo Mid(path, posA, posB - posA^)
echo     Set objHttp = Nothing
)>"IpExterno.vbs"
::inicio
Cscript "IpExterno.vbs" > %fichier%
for /f %%a in ('find /c /v "" ^< !fichier!' ) do set compt=%%a
set /A ligne=216
:ip_publique
for /f "tokens=1,2 delims=:" %%a in ('findstr /n /r . "!fichier!" ^| findstr "^^%ligne%:"') do (set data_ip_publique=%%b)
set ip_publique=!data_ip_publique:~36,13!
::-------------------------------------------------------------------------------



:main
title -==*==-  %titre1% -==*==-
set /A compt=0

net view > %fichier%
for /f %%a in ('find /c /v "" ^< !fichier!' ) do set comptfichier=%%a
set /A depligne=4
set /A compt=!comptfichier!-(1+!depligne!)
set /A comptboucle1=0
(
echo ip_publique:[!ip_publique!]
echo.
echo net view:
)>!resultatScan!

::1ere partie
:boucle1
::recupere hostname du reseau local
for /f "tokens=1,2 delims= " %%a in ('findstr /n /r . "!fichier!" ^| findstr "^^!depligne!:"') do (set data_1=%%a)
set data_1=!data_1:~4,12! 
set host!comptboucle1!=!data_1!
::ping machine
cls
echo Ip publique: !ip_publique!
echo.
echo %titre1%
echo Analyse [!comptboucle1!/!compt!]
echo ping de !host%comptboucle1%!
ping -4 !host%comptboucle1%! > !out!
for /f %%a in ('find /c /v "" ^< !out!' ) do set comptoutping=%%a
echo Recherche ip pour host !host%comptboucle1%!

:boucle2
set /A ligne=2
for /f "tokens=* delims= " %%a in ('findstr /n /r . "!out!" ^| findstr "^^!ligne!:"') do (set data_ping=%%a)
for /f "eol=[ tokens=1,2,3,4,5,6,7 " %%a in ("!data_ping!") do (set dataIP=%%g)
(
echo !host%comptboucle1%!:!dataIP!
)>> !resultatScan!
goto finboucle2

:finboucle2
::compteur
if !comptboucle1!==!compt! goto finboucle1
set /A comptboucle1=!comptboucle1!+1
set /A depligne=!depligne!+1
goto boucle1

:finboucle1
goto finmain

:finmain
goto fin

:fin
call :destruction
endlocal
exit

:destruction
if exist !fichier! echo destruction !fichier! && del !fichier!
if exist !in! echo destruction !in! && del in.bat
if exist !out! echo destruction !out! && del out.bat
if exist "IpExterno.vbs" Del "IpExterno.vbs"
goto:eof
