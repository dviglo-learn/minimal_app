:: Меняем кодировку консоли на UTF-8
chcp 65001

:: Путь к git.exe
set "PATH=c:\program files\git\bin"

:: Качаем репозиторий движка в папку engine
git clone https://github.com/dviglo/dviglo engine

:: Так как в движке могут произойти изменения, ломающие обратную совместимость,
:: то возвращаем состояние репозитория к определённой версии (03.03.2023)
git -C engine reset --hard de79bc776806e0e3b9700c02d75776d5b152d04d

:: Ждём нажатие Enter перед закрытием консоли
pause
