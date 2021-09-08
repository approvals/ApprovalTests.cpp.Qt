<a id="top"></a>

# ApprovalTests.cpp.Qt


[![Build status](https://ci.appveyor.com/api/projects/status/pf8et0nk1mdajskf/branch/master?svg=true)](https://ci.appveyor.com/project/isidore/approvaltests-cpp-qt/branch/master) 
[![Actions Status](https://github.com/approvals/ApprovalTests.cpp.Qt/workflows/build/badge.svg)](https://github.com/approvals/ApprovalTests.cpp.Qt/actions)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

<a href="https://github.com/approvals/ApprovalTests.cpp.Qt/releases/download/v.0.0.3/ApprovalTestsQt.v.0.0.3.hpp">Download the latest version (v.0.0.3) of the **single header file** here.</a>

toc

## Purpose

To enable easy, convenient testing and [Approval Testing](https://github.com/approvals/ApprovalTests.cpp) of [Qt](https://www.qt.io)-based C++ code by using modern test frameworks.

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
* Currently, there are compile-time checks to prevent incorrect use of `QCOMPARE`, but not the others.
* Please note that this is a very early implementation, and there is not yet any promise of a stable interface.

## Reference

### Setting up your main

snippet: catch_2_qt_main

### Verifying a QImage

This takes a QImage, and saves this as a .png, and then verifies it by reading it back in.

In general, it's better to verify behaviour of objects rather than their appearance. However, if you do wish to test the contents of a QImage, this will work well.

snippet: verify_qimage

### Verifying a QTableView, e.g. QTableWidget

This takes QTableView, and saves its text contents in a tab-separated .tsv, for verification.

snippet: verify_table_view

## What's new?

Check out the [Features](/doc/Features.md#top) page or [upcoming release notes](https://github.com/approvals/ApprovalTests.cpp.Qt/blob/master/build/relnotes_x.y.z.md) to see what we've been working on lately, or browse the [past release notes](https://github.com/approvals/ApprovalTests.cpp.Qt/releases).