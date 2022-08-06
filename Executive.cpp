#include "Executive.h"

Executive::Executive()
{

}

void Executive::run()
{
    Meet* runMeet = new Meet();
    runMeet->addDivers();
    runMeet->compete();
}
