@SpringBootApplication
public class MovieApplication{
  public static void main(String[] args){
    SpringBootApplication.run(MovieApplication.run, args);
  }
}

@Document(collection="movies")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Movie{
  @Id
  private ObjectId Id;
  private String title;
  private String imdbId;
  private String trailerLink;
  private String poster;
  private String releaseDate;
  private List<String> genres;
  private List<String> backdrops;
  @DocumentReference
  private List<Review> reviewIds;
}

@Document(collection="reviews")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Review{
  @Id
  private ObjectId Id;
  private String body;
}

@Repository
public interface MovieRepository extends MongoRepository<Movie, ObjectId>{

}

@Service
public class MovieService{
  @Autowired
  MovieRepository movieRepository;

  //get all movies
  public List<Movie> getAllMovies(){
    return movieRepository.findAll();
  }

  //get a movie
  public Optional<Movie> getMovie(ObjectId id){
    return movieRepository.findById(id);
  }
}

@RestController
@GetMapping("/api/v1/movies")
public class MovieController{
  @Autowired
  MovieService movieService;

  @GetMapping
  public ResponseEntity<List<Movie>> getAllMovies(){
    return new ResponseEntity<List<Movie>>(movieService.getAllMovies(), HttpStatus.OK);
  }

  @GetMapping("/{id}")
  public ResponseEntity<Optional<Movie>> getMovie(@PathVariable ObjectId id){
    return new ResponseEntity<Optional<Movie>>(movieService.getMovie(id), HttpStatus.OK);
  }
}
