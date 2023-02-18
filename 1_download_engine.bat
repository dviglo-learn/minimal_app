:: Меняем кодировку консоли на UTF-8
chcp 65001

:: Путь к git.exe
set "PATH=c:\program files\git\bin"

:: Качаем репозиторий движка в папку engine
git clone https://github.com/dviglo/dviglo engine

:: Так как в движке могут произойти изменения, ломающую обратную совместимость,
:: то возвращаем состояние репозитория к определённой версии (18.02.2023)
git -C engine reset --hard a96e82e27839daa8b7762fc6e8cdb0dfa270eec4

:: Ждём нажатие Enter перед закрытием консоли
pause
