#include <BeApp.h>
#include <BeWindow.h>
#include <BeButton.h>
#include <BeTextControl.h>
#include <BeListView.h>
#include <BeMessage.h>
#include <BeString.h>

class CardfileApp : public BApplication {
public:
    CardfileApp() : BApplication("application/x-vnd.Cardfile") {}
    void ReadyToRun() override;
};

class CardfileWindow : public BWindow {
public:
    CardfileWindow() : BWindow(BRect(100, 100, 500, 400), "Cardfile", B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE) {
        // Create the card list view
        fCardListView = new BListView(BRect(10, 10, 390, 310), "CardListView");
        AddChild(fCardListView);

        // Create text input fields
        fTitleInput = new BTextControl(BRect(10, 320, 390, 350), "Title", "Title:", NULL);
        AddChild(fTitleInput);

        fContentInput = new BTextControl(BRect(10, 360, 390, 400), "Content", "Content:", NULL);
        AddChild(fContentInput);

        // Create buttons
        fAddButton = new BButton(BRect(410, 320, 490, 350), "Add", "Add", new BMessage('ADD '));
        AddChild(fAddButton);

        fEditButton = new BButton(BRect(410, 350, 490, 380), "Edit", "Edit", new BMessage('EDIT'));
        AddChild(fEditButton);

        fDeleteButton = new BButton(BRect(410, 380, 490, 410), "Delete", "Delete", new BMessage('DELE'));
        AddChild(fDeleteButton);
    }

    void MessageReceived(BMessage *message) override {
        switch (message->what) {
            case 'ADD ':
                AddCard();
                break;
            case 'EDIT':
                EditCard();
                break;
            case 'DELE':
                DeleteCard();
                break;
            default:
                BWindow::MessageReceived(message);
                break;
        }
    }

private:
    void AddCard() {
        BString title = fTitleInput->Text();
        BString content = fContentInput->Text();
        // Implement card addition logic here
        fCardListView->AddItem(new BStringItem(title + " - " + content));
    }
    
    void EditCard() {
        int32 selectedIndex = fCardListView->CurrentSelection();
        if (selectedIndex >= 0) {
            // Implement card editing logic here
            BStringItem *item = dynamic_cast<BStringItem *>(fCardListView->ItemAt(selectedIndex));
            item->SetText(fTitleInput->Text() + " - " + fContentInput->Text());
        }
    }
    
    void DeleteCard() {
        int32 selectedIndex = fCardListView->CurrentSelection();
        if (selectedIndex >= 0) {
            // Implement card deletion logic here
            delete fCardListView->RemoveItem(selectedIndex);
        }
    }

    BListView *fCardListView;
    BTextControl *fTitleInput;
    BTextControl *fContentInput;
    BButton *fAddButton;
    BButton *fEditButton;
    BButton *fDeleteButton;
};

void CardfileApp::ReadyToRun() {
    CardfileWindow *window = new CardfileWindow();
    window->Show();
}

int main() {
    CardfileApp app;
    app.Run();
    return 0;
}