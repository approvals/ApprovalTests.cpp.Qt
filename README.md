<!--
GENERATED FILE - DO NOT EDIT
This file was generated by [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets).
Source File: /mdsource/README.source.md
To change this file edit the source file and then execute ./run_markdown_templates.sh.
-->

# ApprovalTests.cpp.Qt

<a href="https://github.com/approvals/ApprovalTests.cpp.Qt/releases/download/v.0.0.0/ApprovalTests.v.0.0.0.hpp">Download the latest version (v.0.0.0) of the **single header file** here.</a>

<!-- toc -->
## Contents

  * [Purpose](#purpose)
  * [Features](#features)
  * [Limitations](#limitations)
  * [Reference](#reference)
    * [Setting up your main](#setting-up-your-main)
    * [Verifying a QImage](#verifying-a-qimage)
    * [Verifying a QTableView, e.g. QTableWidget](#verifying-a-qtableview-eg-qtablewidget)
<!-- endtoc -->


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

<!-- snippet: catch_2_qt_main -->
<a id='snippet-catch_2_qt_main'/></a>
```cpp
// main.cpp:
#define APPROVALS_CATCH_QT
#include "ApprovalTestsQt/integrations/catch/Catch2QtApprovals.h"
```
<sup>[snippet source](/tests/Catch2_Tests/main.cpp#L1-L5) / [anchor](#snippet-catch_2_qt_main)</sup>
<!-- endsnippet -->

### Verifying a QImage

<!-- snippet: verify_qimage -->
<a id='snippet-verify_qimage'/></a>
```cpp
QImage image(10, 20, QImage::Format_RGB32);
image.fill(Qt::red);
ApprovalTestsQt::verifyQImage(image);
```
<sup>[snippet source](/tests/Catch2_Tests/ApprovalsQtTests.cpp#L31-L35) / [anchor](#snippet-verify_qimage)</sup>
<!-- endsnippet -->

### Verifying a QTableView, e.g. QTableWidget

<!-- snippet: verify_table_view -->
<a id='snippet-verify_table_view'/></a>
```cpp
QTableWidget tableWidget;
populateTable(tableWidget);
ApprovalTestsQt::verifyQTableView(tableWidget);
```
<sup>[snippet source](/tests/Catch2_Tests/ApprovalsQtTests.cpp#L44-L48) / [anchor](#snippet-verify_table_view)</sup>
<!-- endsnippet -->
