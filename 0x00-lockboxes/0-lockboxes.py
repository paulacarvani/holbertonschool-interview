#!/usr/bin/python3
"""
method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened"""
    unlockBoxes = [0]

    for key in unlockBoxes:
        for item in boxes[key]:
            if item not in unlockBoxes and item < len(boxes):
                unlockBoxes.append(item)
    if len(unlockBoxes) == len(boxes):
        return True
    else:
        return False
