﻿::定时关机脚本
::Author:Tony Chang 
::2016.10.18
::原创代码，转载请注明出处
@echo off
mode con lines=25
setlocal enabledelayedexpansion
title 定时关机
color 1f
cls
set "timeGoal= 21:15"

echo.
echo.
echo.
echo 时间使用24小时制(如2:15)，默认关机时间为:%timeGoal%
echo.
echo 取消已有关机计划 按N;
echo.
echo.当前时间 %time:~0,5%
echo.
echo ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
echo.

set /p "timeGoal= 请输入关机时间:"
echo.
if %timeGoal%==N goto cancel
if %timeGoal%==n goto cancel

set tmp=%timeGoal%
::将"号替换成空格
set /a num = 0
set "tmp=%tmp:"= %"
:next
if not "%tmp:~0,1%"==":" (
 set /a num+=1
 set "tmp=%tmp:~1%"
 goto next
)
set  /a hourNow = %time:~0,2%      
set  /a minuteNow = %time:~3,2%
set  /a secNow = %time:~6,2%
set  /a hourGoal =!timeGoal:~0,%num%!
set /a num+=1
set  /a minuteGoal = !timeGoal:~%num%,2!
set  /a "diffT = hourGoal - hourNow"

::diffT<0;
if %diffT% lss 0 (
echo 将设置为明天%timeGoal%关机
set  /a "diffT = diffT + 24"
)
set  /a "diffT = diffT*3600+(minuteGoal-minuteNow)*60 - secNow"
if %diffT% lss 0 (
echo 将设置为明天%timeGoal%关机
set  /a "diffT = diffT + 86400"
)
shutdown -s -t %diffT%
echo 已设置%timeGoal%的关机计划
goto exit

:cancel
shutdown -a
echo 已取消当前设定
goto exit

:exit
echo.
echo 3秒后退出……
choice /t 3 /d y /n >nul