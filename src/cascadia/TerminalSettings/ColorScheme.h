/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- ColorScheme.hpp

Abstract:
- A color scheme is a single set of colors to use as the terminal colors. These
    schemes are named, and can be used to quickly change all the colors of the
    terminal to another scheme.

Author(s):
- Mike Griese - March 2019

Revision History:
- Converted Table into a map and moved to TerminalSettings project
   from TerminalAppLib (Carlos Zamora, July 2020)

--*/

#pragma once

#include "ColorScheme.g.h"
#include "../inc/cppwinrt_utils.h"
#include "JsonUtils.h"

namespace winrt::Microsoft::Terminal::Settings::Model::implementation
{
    struct ColorScheme : public ColorSchemeT<ColorScheme>
    {
    public:
        ColorScheme();
        ColorScheme(hstring name, uint32_t defaultFg, uint32_t defaultBg, uint32_t cursorColor);
        ~ColorScheme();

        static ColorScheme FromJson(const Json::Value& json);
        bool ShouldBeLayered(const Json::Value& json) const;
        void LayerJson(const Json::Value& json);

        GETSET_PROPERTY(hstring, Name);
        // TODO CARLOS: I can't figure out arrays, for whatever reason
        //GETSET_PROPERTY(uint32_t[], Table);
        GETSET_PROPERTY(uint32_t, Foreground);
        GETSET_PROPERTY(uint32_t, Background);
        GETSET_PROPERTY(uint32_t, SelectionBackground);
        GETSET_PROPERTY(uint32_t, CursorColor);

        static std::optional<std::wstring> GetNameFromJson(const Json::Value& json);
    };
}
