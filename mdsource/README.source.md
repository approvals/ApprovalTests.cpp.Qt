# ApprovalTests.cpp.Qt

<a href="https://github.com/approvals/ApprovalTests.cpp.Qt/releases/download/v.0.0.1/ApprovalTestsQt.v.0.0.1.hpp">Download the latest version (v.0.0.1) of the **single header file** here.</a>

toc

## Purpose

To enable easy, convenient testing and [Approval Testing](https://github.com/approvals/ApprovalTests.cpp.Qt) of [Qt](https://www.qt.io)-based C++ code by using modern test frameworks.

Currently [Catch](https://github.com/catchorg/Catch2) is supported.

## Features

* Creates a QApplication automatically, so that tests that create Qt widgets can run.
* Verify `QImage`. You give it a QImage, it saves this as a .png, and then verifies it by reading it back in.
* Verify `QTableView`. You give it a QTableView, and it saves its text contents in a tab-separated .tsv file.
* Augments ApprovalTests so that .png files are read in to QImage objects which are then compared - this is more reliable and portable than the default behaviour of doing character-by-character comparison of .png files on disk.
* Provides nicely-readable string representations of [a growing range of Qt classes](https://github.com/approvals/ApprovalTests.cpp.Qt/blob/master/ApprovalTestsQt/integrations/catch/Catch2QtStringMaker.h).

## Requirements

* [Qt](https://www.qt.io)'s Widgets and Tests modules

## Getting Started

You can download the [Starter Project](https://github.com/approvals/ApprovalTests.cpp.Qt.StarterProject) and start experimenting.

## Limitations

* **IMPORTANT:** Do not use the [Qt Test macros](https://doc.qt.io/qt-5/qtest.html#macros), such as `QCOMPARE`, `QVERIFY`, `QTRY_COMPARE` and so on. **Currently, any test failures of all any of the Qt Test macros will be silently swallowed, and tests will spuriously pass.**
* Please note that this is a very early implementation, and there is not yet any promise of a stable interface.

## Reference

### Setting up your main

snippet: catch_2_qt_main

### Verifying a QImage

snippet: verify_qimage

### Verifying a QTableView, e.g. QTableWidget

snippet: verify_table_view
