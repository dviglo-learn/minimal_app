#include <dviglo/dviglo_all.h>

// Чтобы везде не писать dviglo::ИмяТипа
using namespace dviglo;

// Главный класс игры
class Game : public Application
{
    // Макрос добавляет в класс информацию о текущем и базовом типе
    DV_OBJECT(Game, Application);

public:
    SharedPtr<SpriteBatch> sprite_batch_;

    // Конструктор класса
    Game()
    {
    }

    // Настройки движка перед инициализацией
    void Setup() override
    {
        engineParameters_[EP_FULL_SCREEN] = false; // Запускаем в окне
        engineParameters_[EP_LOG_NAME] = "game.log";
        engineParameters_[EP_RESOURCE_PATHS] = "game_data;data;core_data";
    }

    // Инициализация игры после инициализации движка
    void Start() override
    {
        Input& input = DV_INPUT;
        input.SetMouseVisible(true); // Отображаем курсор мыши

        sprite_batch_ = new SpriteBatch();
        subscribe_to_event(E_ENDALLVIEWSRENDER, DV_HANDLER(Game, handle_end_all_views_render));
    }

    void handle_end_all_views_render(StringHash eventType, VariantMap& eventData)
    {
        Graphics& graphics = DV_GRAPHICS;
        Input& input = DV_INPUT;
        ResourceCache& cache = DV_RES_CACHE;

        Font* font = cache.GetResource<Font>("fonts/my_font.fnt");
        Vector2 mouse_pos{input.GetMousePosition()};

        graphics.Clear(CLEAR_COLOR, Color::BLACK);

        const String str = "Привет";
        sprite_batch_->draw_string(str, font, 20.f, mouse_pos);
        sprite_batch_->flush();
    }
};

// Указываем движку главный класс игры
DV_DEFINE_APPLICATION_MAIN(Game);
