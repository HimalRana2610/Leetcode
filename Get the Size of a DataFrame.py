import pandas as pd
from typing import List

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    row, column = players.shape
    return [row, column]