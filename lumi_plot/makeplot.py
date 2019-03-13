import matplotlib.pyplot as plt
import datetime as dt

data = open('pages.csv','r').readlines()
data = [d.strip().split(',') for d in data[2:]]

x = [d[0] for d in data]
xdates = [dt.datetime.strptime(date,'%d/%m/%y') for date in x]
y = [p[1] for p in data]

plt.plot(xdates,y)
plt.xticks(rotation=45)
plt.show()
