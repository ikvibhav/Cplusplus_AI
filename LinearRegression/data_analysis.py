import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt


df = pd.read_csv("run_data_combined.csv")
avg_time = df.groupby('epoch')['time(ms)'].agg('mean')
avg_time.plot()
plt.show()