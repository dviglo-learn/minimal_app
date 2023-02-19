:: Меняем кодировку консоли на UTF-8
chcp 65001

:: Путь к git.exe
set "PATH=c:\program files\git\bin"

:: Качаем репозиторий движка в папку engine
git clone https://github.com/dviglo/dviglo engine

:: Так как в движке могут произойти изменения, ломающую обратную совместимость,
:: то возвращаем состояние репозитория к определённой версии (19.02.2023)
git -C engine reset --hard 2608a4f974e19722c5ca805880a8eb925ed54fed

:: Ждём нажатие Enter перед закрытием консоли
pause
