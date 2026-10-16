#pragma once

#include "../SelectableComponent.hpp"
#include <storage/File.hpp>

class BitmapComponent : public SelectableComponent
{
protected:
    std::unique_ptr<File> bitmap_image_file;

public:
    BitmapComponent(ScreenManager* manager, const Vec2i32& position, std::unique_ptr<File> image, int32_t z_layer, Screen* initial_screen = nullptr);
    BitmapComponent(ScreenManager* manager, const Vec2f& screen_percentage, std::unique_ptr<File> image, int32_t z_layer, Screen* initial_screen);
    virtual ~BitmapComponent() = default;

    virtual void Draw(const Screen* screen) override;
};