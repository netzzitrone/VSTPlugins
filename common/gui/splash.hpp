// (c) 2019-2020 Takamitsu Endo
//
// This file is part of Uhhyou Plugins.
//
// Uhhyou Plugins is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Uhhyou Plugins is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Uhhyou Plugins.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "vstgui/vstgui.h"

#include "guistyle.hpp"

#include <string>

namespace Steinberg {
namespace Vst {

using namespace VSTGUI;

class CreditView : public CControl {
public:
  CreditView(const CRect &size, IControlListener *listener) : CControl(size, listener)
  {
    setVisible(false);

    fontIDTitle
      = new CFontDesc(PlugEditorStyle::fontName(), fontSizeTitle, CTxtFace::kBoldFace);
    fontIDText = new CFontDesc(PlugEditorStyle::fontName(), fontSize);
  }

  ~CreditView()
  {
    if (fontIDTitle) fontIDTitle->forget();
    if (fontIDText) fontIDText->forget();
  }

  void draw(CDrawContext *pContext) override;
  CMouseEventResult onMouseDown(CPoint &where, const CButtonState &buttons) override;
  CLASS_METHODS(CreditView, CControl)

private:
  CCoord fontSize = 12.0;
  CCoord fontSizeTitle = 18.0;

  CFontRef fontIDTitle = nullptr;
  CFontRef fontIDText = nullptr;
};

class SplashLabel : public CControl {
public:
  SplashLabel(
    const CRect &size,
    IControlListener *listener,
    int32_t tag,
    CControl *splashView,
    std::string label = "",
    double fontSize = 18.0)
    : CControl(size, listener, tag)
    , splashView(splashView)
    , label(label)
    , fontSize(fontSize)
  {
    if (splashView != nullptr) splashView->remember();
    fontID = new CFontDesc(PlugEditorStyle::fontName(), fontSize, CTxtFace::kBoldFace);
  }

  ~SplashLabel()
  {
    if (splashView != nullptr) splashView->forget();
    if (fontID) fontID->forget();
  }

  CLASS_METHODS(SplashLabel, CControl);

  void draw(CDrawContext *pContext) override;

  CMouseEventResult onMouseDown(CPoint &where, const CButtonState &buttons) override;
  CMouseEventResult onMouseEntered(CPoint &where, const CButtonState &buttons) override;
  CMouseEventResult onMouseExited(CPoint &where, const CButtonState &buttons) override;
  CMouseEventResult onMouseCancel() override;

  void setDefaultFrameColor(CColor color);
  void setHighlightColor(CColor color);
  void setDefaultFrameWidth(float width);
  void setHighlightWidth(float width);

protected:
  CControl *splashView = nullptr;
  std::string label;

  CFontRef fontID = nullptr;
  double fontSize = 18.0;
  CColor fontColor = CColor(0, 0, 0, 255);

  CColor frameColor = CColor(0, 0, 0, 255);
  CColor highlightColor = CColor(0, 0, 0, 255);
  float frameWidth = 1.0f;
  float highlightFrameWidth = 2.0f;

  bool isMouseEntered = false;
};

} // namespace Vst
} // namespace Steinberg
