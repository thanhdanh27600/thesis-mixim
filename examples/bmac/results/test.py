#!/usr/bin/env python
# coding: utf-8

# In[7]:


import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os
from datetime import datetime
import shutil
import logging


# In[8]:


logging.basicConfig(filename=f"log/log-{datetime.now().strftime('%d-%m-%Y %Hh%Mm%Ss')}",
                            filemode='a',
                            format='%(asctime)s,%(msecs)d %(name)s %(levelname)s %(message)s',
                            datefmt='%H:%M:%S',
                            level=logging.DEBUG)

logging.info("Running Localization Log \n")


# In[9]:


end_area = 0
end_error = 0
current_line = 0
backup_file = "./backup/16-02-2022 22h07m49s.vec"
main_file = "General-0.vec"
with open(main_file, "r") as ins:
    file = []
    for line in ins:
        current_line += 1
        file.append(line)
        split_line = line.rstrip().split('	')
        if split_line[0] == '16':
            end_error = current_line
        if split_line[0] == '17':
            end_area = current_line
print(end_area)
print(end_error)
print(len(file))
shutil.copy("General-0.vec", f"./backup/{datetime.now().strftime('%d-%m-%Y %Hh%Mm%Ss')}.vec")


# In[10]:


ERROR = {"start": 21, "end": end_error, "name": "Error"}
AREA= {"start": end_error + 1, "end": end_area, "name": "Area"}
RECORDS = [AREA, ERROR]


# In[11]:


for record in RECORDS:
    data_histogram_x = []
    data_histogram_y= []
    for i in range(record['start']-1, record['end'],1):
        split_line = file[i].rstrip().split('	')
        # print(split_line)

        data_histogram_x.append(float(split_line[2]))
        data_histogram_y.append(float(split_line[3]))

    data_histogram_y_pd = pd.DataFrame(data_histogram_y, columns=[record['name']])
    
    logging.info(data_histogram_y_pd.round(6).describe())
    # Shut down the logger
    logging.shutdown()

    plt.plot(data_histogram_x,data_histogram_y, c="orange")
    
    print(data_histogram_y_pd.round(6).describe())
    fig = plt.gcf()
    fig.set_size_inches(18.5, 10.5)
    fig.savefig(f"{record['name']}.png", dpi=100, facecolor=(1, 1, 1))
    plt.show()
    plt.hist(data_histogram_y, bins=10)
    plt.show()


# In[12]:


delay_pd = pd.DataFrame(np.diff(data_histogram_x), columns=['Delay'])
plt.hist(delay_pd)
print(delay_pd.describe())

