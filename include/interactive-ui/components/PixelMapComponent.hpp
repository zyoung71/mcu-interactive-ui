#pragma once

#include "../SelectableComponent.hpp"
#include "../graphics/Pixel.hpp"

/**
 * Colors in specific pixels based on the vector positions given. Unlike PixelGridComponent,
 * it will ONLY set the pixels based on the vector positions given.
 * Initially inside the constructor, you can pass an array of positions and their colors.
 * The order of pixels will not be retained, unlike PixelGridComponent, and will not be able
 * to perform rotations or mirrors. Use this for designs that require a large space with
 * few pixels, or for icons that do not have square shapes.
 */
class PixelMapComponent : public SelectableComponent
{
protected:
    std::unordered_map<Vec2i32, uint32_t> pixel_map;

public:
    PixelMapComponent(ScreenManager* manager, const Vec2i32& origin, const Vec2i32& dimensions, int32_t z_layer, Screen* initial_screen = nullptr);
    PixelMapComponent(ScreenManager* manager, const Vec2f& screen_percentage, const Vec2i32& dimensions, int32_t z_layer, Screen* initial_screen);
    PixelMapComponent(ScreenManager* manager, const Vec2i32& origin, const Pixel* initial_buffer, size_t buff_length, int32_t z_layer, Screen* initial_screen = nullptr);
    PixelMapComponent(ScreenManager* manager, const Vec2i32& origin, const ArrayView<Pixel>& initial_buffer, int32_t z_layer, Screen* initial_screen = nullptr);
    PixelMapComponent(ScreenManager* manager, const Vec2f& screen_percentage, const Pixel* initial_buffer, size_t buff_length, Screen* initial_screen);
    PixelMapComponent(ScreenManager* manager, const Vec2f& screen_percentage, const ArrayView<Pixel>& initial_buffer, int32_t z_layer, Screen* initial_screen);

    virtual ~PixelMapComponent() = default;

    void SetPixel(Pixel p);
    void ClearPixels();
    void SetPixels(const ArrayView<Pixel>& pixels);
    void SetPixels(const Pixel* pixels, size_t p_count);

    void Draw(const Screen* screen) override;
};