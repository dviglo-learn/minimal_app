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
    Game(Context* context) : Application(context)
    {
    }

    // Настройки движка перед инициализацией
    void Setup() override
    {
        engineParameters_[EP_FULL_SCREEN] = false; // Запускаем в окне
        engineParameters_[EP_LOG_NAME] = "game.log";
        engineParameters_[EP_RESOURCE_PATHS] = "game_data;Data;CoreData";
    }

    // Инициализация игры после инициализации движка
    void Start() override
    {
        Input* input = GetSubsystem<Input>();
        input->SetMouseVisible(true); // Отображаем курсор мыши

        sprite_batch_ = new SpriteBatch(context_);
        SubscribeToEvent(E_ENDALLVIEWSRENDER, DV_HANDLER(Game, handle_end_all_views_render));
    }

    void handle_end_all_views_render(StringHash eventType, VariantMap& eventData)
    {
        Graphics* graphics = GetSubsystem<Graphics>();
        Input* input = GetSubsystem<Input>();
        ResourceCache* cache = GetSubsystem<ResourceCache>();

        Font* font = cache->GetResource<Font>("fonts/my_font.fnt");
        Vector2 mouse_pos{input->GetMousePosition()};

        GetSubsystem<Graphics>()->Clear(CLEAR_COLOR, Color::BLACK);

        const String str = "Привет";
        sprite_batch_->DrawString(str, font, 20.f, mouse_pos);
        sprite_batch_->Flush();
    }
};

// Указываем движку главный класс игры
DV_DEFINE_APPLICATION_MAIN(Game);
