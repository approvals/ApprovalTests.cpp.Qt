* **Breaking changes**
    * None
* **New features**
    * Provides nicely-readable string representations of [a growing range of Qt classes](https://github.com/approvals/ApprovalTests.cpp.Qt/blob/master/ApprovalTestsQt/integrations/catch/Catch2QtStringMaker.h).
    * Verify `QImage`. You give it a QImage, it saves this as a .png, and then verifies it by reading it back in
    * Verify `QTableView`. You give it a QTableView, and it saves its text contents in a tab-separated .tsv file,
    * Works with Catch2
* **Bug fixes**
    * None
* **Other changes**
    * None
