#include <interactive-ui/components/BitmapComponent.hpp>
#include <memory>

BitmapComponent::BitmapComponent(ScreenManager* manager, const Vec2i32& position, std::unique_ptr<File> image, int32_t z_layer, Screen* initial_screen)
    : SelectableComponent(manager, position, z_layer, initial_screen), bitmap_image_file(std::move(image))
{
    int32_t image_width, image_height;
    image->Seek(18);
    image->ReadBuffer(&image_width, 4);
    image->ReadBuffer(&image_height, 4);

    draw_dimensions.xmax = image_width;
    draw_dimensions.ymax = image_height;
}

BitmapComponent::BitmapComponent(ScreenManager* manager, const Vec2f& screen_percentage, std::unique_ptr<File> image, int32_t z_layer, Screen* initial_screen)
    : SelectableComponent(manager, screen_percentage, z_layer, initial_screen), bitmap_image_file(std::move(image))
{
    int32_t image_width, image_height;
    image->Seek(18);
    image->ReadBuffer(&image_width, 4);
    image->ReadBuffer(&image_height, 4);

    draw_dimensions.xmax = image_width;
    draw_dimensions.ymax = image_height;
}

void BitmapComponent::Draw(const Screen *screen)
{
    display->DrawBitmapImage(screen->ToScreenCoords(origin_position - draw_dimensions.min), bitmap_image_file.get());
}