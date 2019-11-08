<!--
GENERATED FILE - DO NOT EDIT
This file was generated by [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets).
Source File: /mdsource/README.source.md
To change this file edit the source file and then execute ./run_markdown_templates.sh.
-->

# ApprovalTests.cpp.Qt

<!-- toc -->
## Contents

  * [Usage](#usage)
  * [Benefits](#benefits)
  * [Reference](#reference)
    * [Setting up your main](#setting-up-your-main)
    * [Verifying a QImage](#verifying-a-qimage)
<!-- endtoc -->


Coming soon...

## Usage

There is not yet a single-header release mechanism, so the individual headers in the ApprovalTestsQt directory need to be included.

## Benefits

* The Catch integration creates a QApplication automatically, so that GUI tests can run.

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
<sup>[snippet source](/tests/Catch2_Tests/ApprovalsQtTests.cpp#L7-L11) / [anchor](#snippet-verify_qimage)</sup>
<!-- endsnippet -->
