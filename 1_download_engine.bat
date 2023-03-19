:: Меняем кодировку консоли на UTF-8
chcp 65001

:: Путь к git.exe
set "PATH=c:\program files\git\bin"

:: Качаем репозиторий движка в папку engine
git clone https://github.com/dviglo/dviglo engine

:: Так как в движке могут произойти изменения, ломающие обратную совместимость,
:: то возвращаем состояние репозитория к определённой версии (19.03.2023)
git -C engine reset --hard 64b6a6f1074f3e81ea80c8b96d4893200b97fcf2

:: Ждём нажатие Enter перед закрытием консоли
pause
