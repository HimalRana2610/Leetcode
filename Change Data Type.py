import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students["age"] = students["age"].astype(str)
    return students