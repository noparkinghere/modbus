RMDIR /S /Q CONVERTER_V1
MD CONVERTER_V1
MD CONVERTER_V1\code_create\
C:\Users\Frank\AppData\Local\Programs\Python\Python38-32\Scripts\pyinstaller.exe -Fw   -i img.ico run.py --workpath temp --distpath CONVERTER_V1 -n "CONVERTER_V1_1.0.exe"
XCOPY /E  .\code_create .\CONVERTER_V1\code_create