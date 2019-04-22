#ifndef RPSGAME_H_
#define RPSGAME_H_

#include "wx/wx.h"
#include "ButtonPanel.h"

/**
 * The main application class.
 */
class RPSGame : public wxApp
{
public:
    /**
     * Initialization function that is called when the application opens.
     * @returns true if the app opened successfully, else returns false.
     */
    virtual bool OnInit() override;
};

#endif /* RPSGAME_H_ */
