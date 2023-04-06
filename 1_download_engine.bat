:: Меняем кодировку консоли на UTF-8
chcp 65001

:: Путь к git.exe
set "PATH=c:\program files\git\bin"

:: Качаем репозиторий движка в папку engine
git clone https://github.com/dviglo/dviglo engine

:: Так как в движке могут произойти изменения, ломающие обратную совместимость,
:: то возвращаем состояние репозитория к определённой версии (06.04.2023)
git -C engine reset --hard fe43065225ef6d6f86dfe8168e3e4b29e8448f08

:: Ждём нажатие Enter перед закрытием консоли
pause
