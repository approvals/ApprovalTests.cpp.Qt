#! /usr/bin/env python3

import sys

sys.path.append('../../ApprovalTests.cpp/build')
from scripts import version
from scripts.prepare_release import build

if __name__ == '__main__':
    build(lambda v: v.update_minor(), deploy=False)
