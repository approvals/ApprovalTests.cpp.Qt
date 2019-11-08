# ApprovalTests.cpp.Qt

toc

Coming soon...

## Usage

There is not yet a single-header release mechanism, so the individual headers in the ApprovalTestsQt directory need to be included.

## Benefits

* The Catch integration creates a QApplication automatically, so that GUI tests can run.
* The Catch integration also augments ApprovalTests so that .png files are read in to QImage objects which are then compared - this is more reliable and portable than the default behaviour of doing character-by-character comparison of .png files on disk.

## Reference

### Setting up your main

snippet: catch_2_qt_main

### Verifying a QImage

snippet: verify_qimage
