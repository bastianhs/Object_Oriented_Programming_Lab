import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Streamer<T> implements IStreamer<T> {

    private List<T> data;

    public Streamer(List<T> data) {
        for (T datum: data) {
            this.data.add(datum);
        }
    }

    public void forEach(Function<T, Void> consumer) {
        for (T datum: data) {
            consumer.apply(datum);
        }
    }

    public <R> IStreamer<R> map(Function<T, R> mapper) {
        Streamer<R> streamer = new Streamer<>(new ArrayList<>());
        for (T datum: data) {
            streamer.data.add(mapper.apply(datum));
        }
        return streamer;
    }

    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        Streamer<T> streamer = new Streamer<>(new ArrayList<>());
        for (int i = 0; i < data.size(); ++i) {
            if (predicate.apply(data.get(i))) {
                streamer.data.add(i, data.get(i));
            }
        }
        for(T datum: data) {
            if (predicate.apply(datum)) {
                streamer.data.add(datum);
            }
        }
        return streamer;
    }

    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R result = initialValue;
        for (T datum: data) {
            result = reducer.apply(result).apply(datum);
        }
        return result;
    }

    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        return new Streamer<>(new ArrayList<>());
    }

    public T findFirst(Function<T, Boolean> predicate) {
        for (int i = 0; i < data.size(); ++i) {
            if (predicate.apply(data.get(i))) {
                return data.get(i);
            }
        }

        return null;
    }

    public T findLast(Function<T, Boolean> predicate) {
        for (int i = data.size() - 1; i > -1; --i) {
            if (predicate.apply(data.get(i))) {
                return data.get(i);
            }
        }

        return null;
    }

    public T head() {
        return data.get(0);
    }

    public IStreamer<T> tail() {
        return new Streamer<>(new ArrayList<>());
    }

    public T last() {
        return data.get(data.size() - 1);
    }

    public IStreamer<T> init() {
        return new Streamer<>(new ArrayList<>());
    }

    public IStreamer<T> takeFirst(int n) {
        return new Streamer<>(new ArrayList<>());
    }

    public IStreamer<T> takeLast(int n) {
        return new Streamer<>(new ArrayList<>());
    }

    public Boolean isEmpty() {
        return null;
    }

    public Integer count() {
        return null;
    }

    public Boolean some(Function<T, Boolean> predicate) {
        return null;
    }

    public Boolean every(Function<T, Boolean> predicate) {
        return null;
    }

    public List<T> collect() {
        return new ArrayList<>();
    }

    public void reverse() {
    }
}
