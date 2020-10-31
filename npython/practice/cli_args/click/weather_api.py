#!/usr/bin/env python3

import requests
import click

SAMPLE_API_KEY='b1b15e88fa797225412429c1c50c122a1'

def current_weather(location, api_key=SAMPLE_API_KEY):
    url='http://samples.openweathermap.org/data/2.5/weather'
    query_params={
        'q': location,
        'appid':api_key,
    }
    response = requests.get(url, params=query_params)
    return response.json()['weather'][0]['description']

# print(current_weather('London')[0]['description'])
@click.command()
@click.argument('location')  # mandatory argument
@click.option('--api-key', '-a', help='your API key for openweathermap API')
def main(location, api_key):
    """
    A little weather tool

    1. London, UK

    2. Canmore

    You need a valid API key from OpenWeatherMap for the tool to work
    """
    weather = current_weather(location, api_key)
    print(f"The weather in {location} right now: {weather}")

if __name__ == "__main__":
    main()
