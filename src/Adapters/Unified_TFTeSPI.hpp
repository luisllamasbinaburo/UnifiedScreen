/***************************************************
Copyright (c) 2021 Luis Llamas
(www.luisllamas.es)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses
****************************************************/

#pragma one

#include "Bases.hpp"

#ifndef TFT_ESPI_VERSION
  #include <TFT_eSPI.h>
#endif

namespace UGFX
{
	class UnifiedScreen_TFTeSPI : public Graphic<uint16_t>
	{
	public:
		UnifiedScreen_TFTeSPI(TFT_eSPI* lcd) { item = lcd; };

		// bitmap implementation
		__attribute__((always_inline)) std::int_fast16_t width() { return item->width(); }
		__attribute__((always_inline)) std::int_fast16_t height() { return item->height(); }

		__attribute__((always_inline)) void drawPixel(int32_t x, int32_t y, uint16_t color) { item->drawPixel(x, y, color); }

		// graphics implementation
		__attribute__((always_inline)) void fillScreen(uint16_t color) { item->fillScreen(color); }

		__attribute__((always_inline)) void drawVerticalLine(int32_t x, int32_t y, int32_t h, uint16_t color) { item->drawFastVLine(x, y, h, color); }
		__attribute__((always_inline)) void drawHorizontalLine(int32_t x, int32_t y, int32_t w, uint16_t color) { item->drawFastHLine(x, y, w, color); }
		__attribute__((always_inline)) void drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint16_t color) { item->drawLine(x0, y0, x1, y1, color); }

		__attribute__((always_inline)) void drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t color) { item->drawRect(x, y, w, h, color); }
		__attribute__((always_inline)) void fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t color) { item->fillRect(x, y, w, h, color); }

		__attribute__((always_inline)) void drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radius, uint16_t color) { item->drawRoundRect(x, y, w, h, radius, color); }
		__attribute__((always_inline)) void fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radius, uint16_t color) { item->fillRoundRect(x, y, w, h, radius, color); }

		__attribute__((always_inline)) void drawCircle(int32_t x, int32_t y, int32_t r, uint16_t color) { item->drawCircle(x, y, r, color); }
		__attribute__((always_inline)) void fillCircle(int32_t x, int32_t y, int32_t r, uint16_t color) { item->fillCircle(x, y, r, color); }

		__attribute__((always_inline)) void drawEllipse(int16_t x, int16_t y, int32_t rx, int32_t ry, uint16_t color) { item->drawEllipse(x, y, rx, ry, color); }
		__attribute__((always_inline)) void fillEllipse(int16_t x, int16_t y, int32_t rx, int32_t ry, uint16_t color) { item->fillEllipse(x, y, rx, ry, color); }

		__attribute__((always_inline)) void drawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint16_t color) { item->drawTriangle(x1, y1, x2, y2, x3, y3, color); }
		__attribute__((always_inline)) void fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint16_t color) { item->fillTriangle(x1, y1, x2, y2, x3, y3, color); }

		// textable implementation
		__attribute__((always_inline)) void setTextSize(uint8_t s) { item->setTextSize(s);}
		__attribute__((always_inline)) void setTextFont(uint8_t f) { item->setTextFont(f);}

		__attribute__((always_inline)) void drawChar(int32_t x, int32_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) { item->drawChar(x, y, c, color, bg, size); }
		__attribute__((always_inline)) void drawString(const String& string, int32_t x, int32_t y, TEXT_ALIGNMENT alignment, uint16_t color)
		{
			item->setTextColor(color);
			item->setTextDatum(alignment);
			item->drawString(string, x, y);
		}

	private:
		TFT_eSPI* item;
	};

	class UnifiedSprite_TFTeSPI : public Graphic<uint16_t>, public ISprite<uint16_t>
	{
	public:
		UnifiedSprite_TFTeSPI(TFT_eSprite* sprite) { item = sprite; };

		// bitmap implementation
		__attribute__((always_inline)) std::int_fast16_t width() { return item->width(); }
		__attribute__((always_inline)) std::int_fast16_t height() { return item->height(); }

		__attribute__((always_inline)) void drawPixel(int32_t x, int32_t y, uint16_t color) { item->drawPixel(x, y, color); }

		// readable bitmap implementation
		__attribute__((always_inline)) uint16_t readPixel(int32_t x, int32_t y) { return item->readPixel(x, y); }

		// graphics implementation
		__attribute__((always_inline)) void fillScreen(uint16_t color) { item->fillScreen(color); }

		__attribute__((always_inline)) void drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint16_t color) { item->drawLine(x0, y0, x1, y1, color); }
		__attribute__((always_inline)) void drawVerticalLine(int32_t x, int32_t y, int32_t h, uint16_t color) { item->drawFastVLine(x, y, h, color); }
		__attribute__((always_inline)) void drawHorizontalLine(int32_t x, int32_t y, int32_t w, uint16_t color) { item->drawFastHLine(x, y, w, color); }

		__attribute__((always_inline)) void drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t color) { item->drawRect(x, y, w, h, color); }
		__attribute__((always_inline)) void fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t color) { item->fillRect(x, y, w, h, color); }

		__attribute__((always_inline)) void drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radius, uint16_t color) { item->drawRoundRect(x, y, w, h, radius, color); }
		__attribute__((always_inline)) void fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radius, uint16_t color) { item->fillRoundRect(x, y, w, h, radius, color); }

		__attribute__((always_inline)) void drawCircle(int32_t x, int32_t y, int32_t r, uint16_t color) { item->drawCircle(x, y, r, color); }
		__attribute__((always_inline)) void fillCircle(int32_t x, int32_t y, int32_t r, uint16_t color) { item->fillCircle(x, y, r, color); }

		__attribute__((always_inline)) void drawEllipse(int16_t x, int16_t y, int32_t rx, int32_t ry, uint16_t color) { item->drawEllipse(x, y, rx, ry, color); }
		__attribute__((always_inline)) void fillEllipse(int16_t x, int16_t y, int32_t rx, int32_t ry, uint16_t color) { item->fillEllipse(x, y, rx, ry, color); }

		__attribute__((always_inline)) void drawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint16_t color) { item->drawTriangle(x1, y1, x2, y2, x3, y3, color); }
		__attribute__((always_inline)) void fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint16_t color) { item->fillTriangle(x1, y1, x2, y2, x3, y3, color); }

		// sprite implementation
		__attribute__((always_inline)) void* setColorDepth(int8_t depth) { return item->setColorDepth(depth); }

		__attribute__((always_inline)) void* createSprite(int16_t width, int16_t height, uint8_t frames = 1) { return item->createSprite(width, height, frames); }
		__attribute__((always_inline)) void deleteSprite(void) { item->deleteSprite(); }

		__attribute__((always_inline)) void pushSprite(int32_t x, int32_t y) { item->pushSprite(x, y); }
		__attribute__((always_inline)) void pushSprite(int32_t x, int32_t y, uint16_t transparent) { item->pushSprite(x, y, transparent); }

		__attribute__((always_inline)) bool pushRotated(int16_t angle, uint16_t transparent = -1) { item->pushRotated(angle, transparent); }

		// textable implementation
		__attribute__((always_inline)) void setTextSize(uint8_t s) { item->setTextSize(s);}
		__attribute__((always_inline)) void setTextFont(uint8_t f) { item->setTextFont(f);}

		__attribute__((always_inline)) void drawChar(int32_t x, int32_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) { item->drawChar(x, y, c, color, bg, size); }
		__attribute__((always_inline)) void drawString(const String& string, int32_t x, int32_t y, TEXT_ALIGNMENT alignment, uint16_t color)
		{
			item->setTextColor(color);
			item->setTextDatum(alignment);
			item->drawString(string, x, y);
		}

	private:
		TFT_eSprite* item;
	};

}