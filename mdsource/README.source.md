# ApprovalTests.cpp.Qt

toc

## Purpose

To enable easy, convenient testing and [Approval Testing](https://github.com/approvals/ApprovalTests.cpp.Qt) of [Qt](https://www.qt.io)-based C++ code by using modern test frameworks.

Currently [Catch](https://github.com/catchorg/Catch2) is supported.

## Features

* Creates a QApplication automatically, so that tests that create Qt widgets can run.
* Augments ApprovalTests so that .png files are read in to QImage objects which are then compared - this is more reliable and portable than the default behaviour of doing character-by-character comparison of .png files on disk.
* Provides nicely-readable string representations of [a growing range of Qt classes](https://github.com/approvals/ApprovalTests.cpp.Qt/blob/master/ApprovalTestsQt/integrations/catch/Catch2QtStringMaker.h).

## Limitations

* There is not yet a single-header release mechanism, so the individual headers in the ApprovalTestsQt directory need to be included.
* **IMPORTANT:** Do not use the [Qt Test macros](https://doc.qt.io/qt-5/qtest.html#macros), such as `QCOMPARE`, `QVERIFY`, `QTRY_COMPARE` and so on. **Currently, any test failures of all any of the Qt Test macros will be silently swallowed, and tests will spuriously pass.**
* Please note that this is a very early implementation, and there is not yet any promise of a stable interface.

## Reference

### Setting up your main

snippet: catch_2_qt_main

### Verifying a QImage

snippet: verify_qimage
