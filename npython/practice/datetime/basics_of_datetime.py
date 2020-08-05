#!/usr/bin/env python3

import datetime
import pytz  # you can install it with pip3 install --user pytz

print("Things related to date")
# pass regular integer, without leading 0
# datetime.date(2019, 07, 03)  this is wrong
d = datetime.date(2016, 7, 24)
print(d)

tday = datetime.date.today()
print(tday)
print(tday.day)
print(tday.year)
print(tday.month)
# weekday => Monday - 0, Sunday - 6
# isoweekday => Monday - 1, Sunday - 7
print(tday.weekday())
print(tday.isoweekday())


# time delta (difference bt. two dates or time)
tdelta = datetime.timedelta(days=7)
print(tdelta)
print(tday + tdelta)
print(tday - tdelta)

# date2 = date1 + timedelta
# timedelta = date1 + date2

new_tdelta = tday - d
print(new_tdelta)
print(new_tdelta.total_seconds())


print("Things related to time now")

t = datetime.time(9, 30, 45, 123456)
print(t)
print("Hour " + str(t.hour))
print("Minute " + str(t.minute))
print("Seconds " + str(t.second))
print("Micro seconds " + str(t.microsecond))


print("Things related to datetime")

dt = datetime.datetime(2019, 2, 4, 12, 59, 20, 132949)
print("full: " + str(dt))
print("date: " + str(dt.date()))
print("time: " + str(dt.time()))
print("year: " + str(dt.year))
print("minutes: " + str(dt.minute))

print("Datetime timedelta")

# things like seconds should not be greater than a day or microseconds should
# not be greater than a second etc.
tdelta_dt = datetime.timedelta(days = 365, hours = 12, minutes = 59, seconds = 86399, microseconds = 99999)
print(dt + tdelta_dt)


print("Alternative constructor of datetime")
# no timezone passing
dt_today = datetime.datetime.today()
# can pass timezone
dt_now = datetime.datetime.now()
# just utc timezone, but tzinfo is still none
dt_utcnow = datetime.datetime.utcnow()
print(dt_today)
print(dt_now)
print(dt_utcnow)


print("Using pytz for timezone aware time")
dt_tz = datetime.datetime(2019, 2, 4, 12, 59, 20, 132949, tzinfo=pytz.UTC)
print(dt_tz)

dt_now_tz = datetime.datetime.now(tz=pytz.UTC)
print(dt_now_tz)

dt_utcnow_tz = datetime.datetime.utcnow().replace(tzinfo=pytz.UTC)
print(dt_utcnow_tz)

print("Change to different timezone")
dt_mtn = dt_utcnow_tz.astimezone(pytz.timezone('Asia/Kolkata'))
print("Current Time: " + str(dt_mtn))
print("UTC offset: " + str(dt_mtn.utcoffset()))
print("Time: " + str(dt_mtn.time()))
print("Date: " + str(dt_mtn.date()))


print("List of all timzones")
count = 0
for tz in pytz.all_timezones:
    count += 1
    print(tz)
print("Total timzones: ", count)


# make the naive datetime timzone aware
localtime = datetime.datetime.now()  # isn't timzone aware
mtn_tz = pytz.timezone('US/Mountain')
# convert to another timezone (working)
dt_east = localtime.astimezone(pytz.timezone('US/Eastern'))
new_dt_mount = mtn_tz.localize(localtime)
print(dt_east)
print(new_dt_mount)


# best way to save these dates or pass them around for internal use would be the iso format
dt_mtn = datetime.datetime.now(tz=pytz.timezone('US/Mountain'))
print(dt_mtn)
print(dt_mtn.strftime('%B %d, %Y'))

dt_str = dt_mtn.strftime('%B %d, %Y')  # the right hand operand is a string "month day, year"
# so, you can perform string operations on it not datetime operations
# convert for datetime operations
dt_strp = datetime.datetime.strptime(dt_str, '%B %d, %Y')
print(dt_strp)
# strftime - Datetime to String
# strptime - String to Datetime
