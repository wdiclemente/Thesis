#!/bin/bash
###-------------------------------------------------------###
###------Script to for adding page length to history------###
###-------------------------------------------------------###

DIFFERENT_DATE=0
DIFFERENT_PAGE_NUMBER=0
GREATER_PAGE_NUMER=0

CHECK_DIFF_DATE="$(diff <(tail -1 lumi_plot/pages.csv | cut -d, -f1) <(echo "`date '+%d/%m/%y'`"))"
CHECK_DIFF_PAGE="$(diff <(tail -1 lumi_plot/pages.csv | awk '{print $2}') <(echo "`pdfinfo thesis.pdf | grep Pages | awk '{print $2}'`"))"

if [ "$CHECK_DIFF_DATE" != "" ]
then 
  echo "@@   - The date compiled is different from latest history entry"
  DIFFERENT_DATE=1
fi


if [ "$CHECK_DIFF_PAGE" != "" ]
then 
  echo "@@   - The page number of the pdf is different from the lastest history entry"
  DIFFERENT_PAGE_NUMBER=1
fi


if [ $DIFFERENT_DATE -eq 0 ]  && [ $DIFFERENT_PAGE_NUMBER -eq 0 ]
then 
  echo "@@   - There are the same amount of pages on the same day, not adding anything"
fi

PAGE_COMPILE="$(echo "`pdfinfo thesis.pdf | grep Pages | awk '{print $2}'`")"
PAGE_HISTORY="$(tail -1 lumi_plot/pages.csv | awk '{print $2}')"


if [ $PAGE_COMPILE -gt $PAGE_HISTORY ]
then 
  echo "@@   - Compiled document has greater amount of pages"
  GREATER_PAGE_NUMER=1
fi

if [ $DIFFERENT_DATE -eq 1 ] 
then 
  echo "@@   - Adding entry to history"
  echo "`date '+%d/%m/%y,'` `pdfinfo thesis.pdf | grep Pages | awk '{print $2}'`" >> lumi_plot/pages.csv 
fi 

if [ $DIFFERENT_DATE -eq 0 ]  && [ $GREATER_PAGE_NUMER -eq 1 ]
then 
  echo "@@   - Rewriting last entry history since page number is greater with same date"
  sed -i '$ d' lumi_plot/pages.csv
  echo "`date '+%d/%m/%y,'` `pdfinfo thesis.pdf | grep Pages | awk '{print $2}'`" >> lumi_plot/pages.csv 
fi 
