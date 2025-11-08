import numpy as np
import pandas as pd
from openpyxl import Workbook
from openpyxl.utils.dataframe import dataframe_to_rows

data = {
    'Name': ['Tom', 'Nick', 'Krish', 'Jack'],
    'Age': [20, 21, 19, 18],
    'Score': [87, 24, 97, 45]
}

if __name__ == '__main__':
    # 1. Print numbers 1–10
    for i in range(1, 11):
        print(i)

    # 2. Read numbers and calculate sum
    try:
        numbers = list(map(int, input("Enter numbers separated by space: ").split()))
        print(f"Sum: {sum(numbers)}")
    except ValueError:
        print("Enter only numbers separated by spaces!")

    # 3. NumPy 3x3 matrix
    print("3x3 Matrix:\n", np.array([[1,2,3],[4,5,6],[7,8,9]]))

    # 4. Create DataFrame
    df = pd.DataFrame(data)
    print(df)

    # 5. Save DataFrame to Excel
    wb = Workbook()
    ws = wb.active

    for row in dataframe_to_rows(df, index=False, header=True):
        ws.append(row)

    file_path = "dataframe_output.xlsx"
    wb.save(file_path)
    print(f"DataFrame successfully saved to {file_path}")
