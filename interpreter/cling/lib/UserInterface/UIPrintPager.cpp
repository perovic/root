//------------------------------------------------------------------------------
// CLING - the C++ LLVM-based InterpreterG :)
// author:  Boris Perovic <boris.perovic@cern.ch>
//
// This file is dual-licensed: you can choose to license it under the University
// of Illinois Open Source License or the GNU Lesser General Public License. See
// LICENSE.TXT for details.
//------------------------------------------------------------------------------

#include "cling/UserInterface/UserInterface.h"
#include "cling/Interpreter/IPrintPager.h"
#include "textinput/TextInput.h"

#include <memory>

#include "llvm/Support/raw_ostream.h"

namespace {

  class UIPrintPager : public cling::IPrintPager {
    textinput::TextInput* myTI;
    void switchMode(bool raw);
  public:
    UIPrintPager(textinput::TextInput* TI) {
      myTI = TI;
    }
    void printPaged(llvm::raw_ostream &Out, std::string text);
  };

    void UIPrintPager::printPaged(llvm::raw_ostream &Out, std::string text) {
      unsigned long length = text.length();
      unsigned int n = 400; // == 5 lines (default terminal line width == 80 characters)
      if (length < n) {
        Out << text << "\n";
      } else {
        Out << "Interactive printing. Press Enter to continue, q to stop.\n";
        unsigned int i = 0;
        while (i < length) {
          Out << text.substr(0, n);
          Out.flush();
          i += n;

          if (i < length) {

            // Keep reading input until Enter or [q|Q] is encountered
            char c = 0;
            while (c != '\n' && c != '\r' && c != 'q' && c != 'Q') {
              c = myTI->ReadHiddenCharBlocking();
            }

            // If [q|Q] is encountered, exit the interactive printing
            if (c == 'q' || c == 'Q') {
              break;
            }
              // If Enter is encountered, continue with the printing
            else {
              // Continue with the printing
              text = text.substr(n);
            }

          }
        }
        Out << "\n";
      }
    }

}

namespace cling {

  std::unique_ptr<IPrintPager> UserInterface::makePrintPager(textinput::TextInput *TI) {
    std::unique_ptr<UIPrintPager> up(new UIPrintPager(TI));
    return move(up);
  }
}
