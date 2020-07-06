#ifndef MOUSE_HPP
#define MOUSE_HPP

namespace Mouse
{
    enum class Action : int
    {
	    Release,
	    Press
	};

    enum class Code : int
    {
        None = -1,

        Button0,
        Button1,
        Button2,
        Button3,
        Button4,
        Button5,
        Button6,
        Button7,

        ButtonLeft   = Button0,
        ButtonRight  = Button1,
        ButtonMiddle = Button2
	};
}

#endif