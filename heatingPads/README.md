# Heating Pad

The purpose of this project is to create a heating pad
that will heat various objects in near skin temperatures.

For this, 2 heating pads are used that wrap the object(s)
and a temperature sensor that measures the temperature.
When the max temperature is reached, the heating pads turn off until
the temperature reaches a threshold whre they turn on again.

At the moment, the max temperature is hardcoded to 25 degrees celsius,
but a future improvement is to be controlled using a bluetooth transmitter.
The current temperature should be displayed to an LCD screen (TODO).

### Limitations

The heating pads seem to have a really low max temperature by nature,
thus not being able to efficiently heat an object.
Another heating pad type should be used, but arduino can only provide 5V.

Maybe I should experiment with solid State Relay (SSR),
but that would make the circuit dependent in higher voltage that only a battery or a plug may be able to provide.
