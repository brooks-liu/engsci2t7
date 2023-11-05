hedons = 0
health_points = 0
tired = False
tired_of_stars = False

time_since_run = 121
time_since_textbooks = 121  #
last_star_time = 121  # after
second_last_star_time = 121  # after
previous_activity = "nothing"  # after
star_activity = "nothing"   # after
previous_activity_length = 0  # after

def initialize():
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    hedons = 0
    health_points = 0
    tired = False
    tired_of_stars = False

    previous_activity = "nothing"
    star_activity = "nothing"
    previous_activity_length = 0
    time_since_run = 121
    time_since_textbooks = 121
    last_star_time = 121
    second_last_star_time = 121

def get_cur_hedons():
    global hedons
    return hedons

def get_cur_health():
    global health_points
    return health_points

def offer_star(activity):
    global tired_of_stars, last_star_time, second_last_star_time, star_activity

    if last_star_time <= 120 and second_last_star_time <= 120:
        tired_of_stars = True

    if tired_of_stars == True:
        # maybe make a variable called tired_of_stars
        star_activity = "nothing"
    else:
        last_star_time, second_last_star_time = 0, last_star_time
        star_activity = activity

def star_can_be_taken(activity):
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    # if tired_of_stars == False and star_activity == activity:
    #     return True
    # else:
    #     return False
    
    return tired_of_stars == False and star_activity == activity

def perform_activity(activity, duration):
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    # globals
    if time_since_run < 120 or time_since_textbooks < 120:
        tired = True
    else:
        tired = False

    # tired = True if time_since_run < 120 or time_since_textbooks < 120 else False

    time_since_run += duration
    time_since_textbooks += duration
    last_star_time += duration
    second_last_star_time += duration

    # star + running
    if activity == "running":
        # hedons
        if tired == False:
            for i in range(1, duration + 1):
                if i <= 10:
                    hedons += 2
                elif i > 10:
                    hedons -= 2
                else:
                    pass
        elif tired == True:
            for i in range(1, duration + 1):
                hedons -= 2
        else:
            pass

        if star_activity ==  "running":
            for i in range (1, min(11, duration + 1)):
                hedons += 3
        else:
            pass

        # health_ points
        if previous_activity == "running":
            duration += previous_activity_length
            for i in range(1, duration + 1):
                if i <= 180:
                    health_points += 3
                elif i > 180:
                    health_points += 1
                else:
                    pass
            for i in range(1, previous_activity_length + 1):
                if i <= 180:
                    health_points -= 3
                elif i > 180:
                    health_points -= 1
                else:
                    pass
        else:
            for i in range(1, duration + 1):
                if i <= 180:
                    health_points += 3
                elif i > 180:
                    health_points += 1
                else:
                    pass
        previous_activity = "running"
        time_since_run = 0

    elif activity == "textbooks":
        # hedons
        if tired == False:
            for i in range(1, duration + 1):
                if i <= 20:
                    hedons += 1
                elif i > 20:
                    hedons -= 1
                else:
                    pass
        elif tired == True:
            for i in range(1, duration + 1):
                hedons -= 2
        else:
            pass

        if star_activity ==  "textbooks":
            for i in range (1, min(11, duration + 1)):
                hedons += 3
        else:
            pass

        # health_points
        health_points += 2 * duration

        previous_activity = "textbooks"
        time_since_run = 0

    elif activity == "resting":
        previous_activity = "resting"

    else:
        pass

    #globals
    star_activity = "nothing"
    previous_activity_length = duration
    if time_since_run < 120 or time_since_textbooks < 120:
        tired = True
    else:
        tired = False

def most_fun_activity_minute():
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    if tired == True:
        if star_activity == "running":
            return "running"
        elif star_activity == "textbooks":
            return "textbooks"
        else:
            return "resting"
    elif tired == False:
        if star_activity == "running":
            return "running"
        elif star_activity == "textbooks":
            return "textbooks"
        else:
            return "running"


