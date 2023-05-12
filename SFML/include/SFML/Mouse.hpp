//
3 // SFML - Simple and Fast Multimedia Library
4 // Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
5 //
6 // This software is provided 'as-is', without any express or implied warranty.
7 // In no event will the authors be held liable for any damages arising from the use of this software.
8 //
9 // Permission is granted to anyone to use this software for any purpose,
10 // including commercial applications, and to alter it and redistribute it freely,
11 // subject to the following restrictions:
12 //
13 // 1. The origin of this software must not be misrepresented;
14 //    you must not claim that you wrote the original software.
15 //    If you use this software in a product, an acknowledgment
16 //    in the product documentation would be appreciated but is not required.
17 //
18 // 2. Altered source versions must be plainly marked as such,
19 //    and must not be misrepresented as being the original software.
20 //
21 // 3. This notice may not be removed or altered from any source distribution.
22 //
24
25 #ifndef SFML_MOUSE_HPP
26 #define SFML_MOUSE_HPP
27
29 // Headers
31 #include <SFML/Window/Export.hpp>
32 #include <SFML/System/Vector2.hpp>
33
34
35 namespace sf
36 {
	37 class Window;
	38
		43 class SFML_WINDOW_API Mouse
		44 {
		45 public:
			46
				51     enum Button
				52     {
				53         Left,
					54         Right,
					55         Middle,
					56         XButton1,
					57         XButton2,
					58
					59         ButtonCount
					60     };
			61
				66     enum Wheel
				67     {
				68         VerticalWheel,
					69         HorizontalWheel
					70     };
			71
				80     static bool isButtonPressed(Button button);
			81
				91     static Vector2i getPosition();
			92
				104     static Vector2i getPosition(const Window& relativeTo);
			105
				115     static void setPosition(const Vector2i& position);
			116
				127     static void setPosition(const Vector2i& position, const Window& relativeTo);
			128 };
	129
		130 } // namespace sf
131
132
133 #endif // SFML_MOUSE_HPP
134