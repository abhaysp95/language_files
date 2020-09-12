#!/usr/bin/env python3

'''
dummy data for different usecases
'''

from random import randint, choice

first_names = [ "Celia", "Georgann", "Marya", "Sunni", "Brant", "Bettyann", "Elayne", "Martine", "Marine", "Yuk", "Anibal", "Scottie", "Lessie", "Terisa", "Trish", "Loise", "Brianna", "Piper", "Aurore", "Genesis", "Micah", "Russell", "Wilfredo", "Ela", "Jasper", "Mikel", "Christy", "Gricelda", "Elvera", "Brittaney", "Hubert", "Tisa", "Sherika", "Margit", "Rufina", "Roselle", "Renata", "Mandy", "Shanti", "Nadia", "Valeria", "Tania", "Jody", "Elwanda", "Erlinda", "Lanita", "Neida", "Piedad", "Latrina", "Elke" ]

last_names = [ "Hollister", "Macpherson", "Robare", "Headley", "Tarrance", "Cusic", "Low", "Yadon", "Rittenhouse", "Epstein", "Bonanno", "Imhoff", "Studley", "Marth", "Creighton", "Klosterman", "Laverriere", "Sutherland", "Delosreyes", "Rainey", "Medellin", "Udell", "Remmers", "Alvino", "Hillier", "Gallman", "Chavis", "Ung", "Guadarrama", "Youngblood", "German", "Solt", "Dark", "Letarte", "Rothenberger", "Harbuck", "Bresnahan", "Blevins", "Mullane", "Heston", "Samaniego", "Grippo", "Bedwell", "Twilley", "Noonkester", "Swartwood", "Mormon", "Marmolejo", "Pera", "Baize" ]

street_names = [ "Stanhope Road", "The Moorings", "Riverside Drive", "Lancaster Avenue", "Oxford Street", "Swan Street", "Ivy Lane", "North Road", "Lakeside", "Willow Close", "Station Road", "Mount Street", "New Street", "Belvedere Road", "St Michael's Road", "The Gardens", "Coronation Street", "The Nook", "Laburnum Close", "Ferndale Road", "Shelley Road", "Kent Close", "Princes Street", "Meadow Road", "Mount Pleasant Road", "North Avenue", "Canterbury Close", "Albion Street", "Granville Street", "Herbert Street" ]

cities_names = [ "Neenah", "Belleville", "Glenwood Springs", "Anacortes", "Enfield", "Saint Charles", "Florissant", "Stillwater", "Bellefontaine", "Suffolk", "Yuba City", "Junction City", "Fairfield", "Ogdensburg", "Williamson", "Belen", "Eufaula", "Webster City", "Macomb", "Clearwater", "Alva", "Natick", "New Orleans", "Braintree", "Casper", "Lufkin", "La Grange", "Leavenworth", "Norristown", "San Marcos", "North College Hill", "Jonesboro", "Honesdale", "Opelousas", "Roanoke", "Kellogg", "Aberdeen", "Keokuk", "Englewood", "Denton", "Houma", "Amarillo", "Cairo", "Racine", "Coronado", "Las Vegas", "Bath", "Frankfort", "Delta", "Harrisburg", "Waterford", "Culver City", "Elmira", "Shaker Heights", "Sausalito", "Taos", "Flagstaff", "Silverton", "Cody", "Manchester" ]

fake_cities = [ "East Virnon", "Fort Hautena Du Sidethe", "Blofic", "East Wkenterhav", "Igxvil Haven", "Ntertewksglass City", "Leyred", "Raames", "Moseslan", "Ngelesle Du Nabcuyaington", "Ntaingle", "Great Binswin Du Reddroyal", "Cape Newsro", "Nticthton Du Praiyu City", "Park Neautsandrouge", "Ledgeso Bay", "Booquences Bend", "Myrtnoa Bay", "Cogis Du Skehar Valley", "Chenzoo", "Lake Fobel Du Colles", "Park Frenchthamp", "Suthorpe", "Grand Chrimon", "La Hopelom", "Vanlaiefalls", "Centrelakeoy City", "Buspasionton", "Las Gonlows", "Deerlea City", "El Singcu Du Plainshood", "Saint Boselklon", "Mount Mersniles", "San Charlestintruth", "Cape Doru", "Fort Plagrand", "La Rai", "Park Pidsloo Du Pineri", "Rnardihias", "Churchprice", "Mount Memmin", "Santa Georgenat", "Las Teceantul", "Jefsault Du Rysostown", "Nersat", "El Mos", "Oki", "El Niza Du Thamfort", "Grand Mensnca Du Terslege", "Cerdence", "Grand Yorkwan", "Mount Vymond", "Cape Juncline", "Lake Tierraldi", "New Turbia", "Soupro", "Holten Creek", "San Ganhills", "El Kent", "Vil Bend" ]

state_names = [ "AA", "AE", "AK", "AL", "AP", "AR", "AS", "AZ", "CA", "CO", "CT", "DC", "DE", "FL", "GA", "GU", "HI", "IA", "ID", "IL", "IN", "KS", "KY", "LA", "MA", "MD", "ME", "MI", "MN", "MO", "MS", "MT", "NC", "ND", "NE", "NH", "NJ", "NM", "NV", "NY", "OH", "OK", "OR", "PA", "PR", "RI", "SC", "SD", "TN", "TX", "UT", "VA", "VI", "VT", "WA", "WI", "WV", "WY" ]

full_state_names = [ "Armed Forces America", "Armed Forces", "Alaska", "Alabama", "Armed Forces Pacific", "Arkansas", "American Samoa", "Arizona", "California", "Colorado", "Connecticut", "Washington DC", "Delaware", "Florida", "Georgia", "Guam", "Hawaii", "Iowa", "Idaho", "Illinois", "Indiana", "Kansas", "Kentucky", "Louisiana", "Massachusetts", "Maryland", "Maine", "Michigan", "Minnesota", "Missouri", "Mississippi", "Montana", "North Carolina", "North Dakota", "Nebraska", "New Hampshire", "New Jersey", "New Mexico", "Nevada", "New York", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Puerto Rico", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Virginia", "Virgin Islands", "Vermont", "Washington", "Wisconsin", "West Virginia", "Wyoming" ]

for num in range(100):
    first = choice(first_names)
    last = choice(last_names)

    phone_num = f'{randint(100, 999)}-555-{randint(1000, 9999)}'

    street_num = randint(100, 999)
    street = choice(street_names)
    city = choice(fake_cities)
    state = choice(state_names)
    zip_code = randint(10000, 99999)
    address = f'{street_num} {street} St., {city} {state} {zip_code}'

    email = first.lower() + last.lower() + '@xyzmail.com'

    print(f'{first} {last}\n{phone_num}\n{address}\n{email}\n')
