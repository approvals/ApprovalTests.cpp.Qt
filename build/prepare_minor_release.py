#! /usr/bin/env python3

import sys


sys.path.append('../../ApprovalTests.cpp/build')
from scripts import version
from scripts.prepare_release import build
from scripts_qt.qt_project_details import qt_project_details

if __name__ == '__main__':
    build(lambda v: v.update_minor(), deploy=False, project_details=qt_project_details())
