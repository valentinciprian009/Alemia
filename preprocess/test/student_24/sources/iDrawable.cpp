#include "iDrawable.h"

std::ostream& operator<<(std::ostream& out, const iDrawable& toPrint)
{
	toPrint.print();
	return out;
}
